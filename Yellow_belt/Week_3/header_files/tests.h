#pragma once

#include "test_runner.h"
#include "synonyms.h"

void TestAddSynonyms() {
    {
        Synonyms empty;
        AddSynonyms(empty, "a", "b");
        const Synonyms expected = {
                {"a", {"b"}},
                {"b", {"a"}}
        };
        AssertEqual(empty, expected, "Add to empty");
    }
    {
        Synonyms synonyms = {
                {"a", {"b"}},
                {"b", {"a", "c"}},
                {"c", {"b"}}
        };
        AddSynonyms(synonyms, "a", "c");
        const Synonyms expected = {
                {"a", {"b", "c"}},
                {"b", {"a", "c"}},
                {"c", {"b", "a"}}
        };
        AssertEqual(synonyms, expected, "Add to non-empty");
    }
}

void TestSynonymsCount() {
    {
        Synonyms empty;
//        assert(GetSynonymCount(empty, "a") == 0);
        AssertEqual(GetSynonymCount(empty, "a"), 0u, "count for empty");
    }
    {
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        AssertEqual(GetSynonymCount(synonyms, "a"), 2, "count for a");
        AssertEqual(GetSynonymCount(synonyms, "b"), 1, "count for b");
        AssertEqual(GetSynonymCount(synonyms, "z"),0, "count for z");
    }
}

void TestAreSynonyms() {
    {
        Synonyms empty;
        Assert(!AreSynonyms(empty, "a", "b"), "");
        Assert(!AreSynonyms(empty, "b", "a"), "");
        Synonyms synonyms = {
                {"a", {"b", "c"}},
                {"b", {"a"}},
                {"c", {"a"}}
        };
        Assert(AreSynonyms(synonyms, "a", "b"), "");
        Assert(AreSynonyms(synonyms, "b", "a"), "");
        Assert(AreSynonyms(synonyms, "a", "c"), "");
        Assert(AreSynonyms(synonyms, "c", "a"), "");
        Assert(!AreSynonyms(synonyms, "b", "c"), "");
        Assert(!AreSynonyms(synonyms, "c", "b"), "");
    }
}

void Test() {
    TestRunner tr;
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
    tr.RunTest(TestSynonymsCount, "TestSynonymsCount");
}
