#include <gtest/gtest.h>

#include "BST.hpp" // Include your BST class

TEST(BSTTest, InsertAndSearch) {
    BST<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(15);
    tree.Insert(7);
    tree.Insert(3);

    EXPECT_EQ(tree.Search(10), std::optional<int>(10));
    EXPECT_EQ(tree.Search(5), std::optional<int>(5));
    EXPECT_EQ(tree.Search(15), std::optional<int>(15));
    EXPECT_EQ(tree.Search(7), std::optional<int>(7));
    EXPECT_EQ(tree.Search(3), std::optional<int>(3));
    EXPECT_EQ(tree.Search(999), std::nullopt);
}

TEST(BSTTest, RemoveLeaf) {
    BST<int> tree;
    tree.Insert(8);
    tree.Insert(4);
    tree.Insert(12);

    EXPECT_TRUE(tree.Remove(4));
    EXPECT_EQ(tree.Search(4), std::nullopt);
}

TEST(BSTTest, RemoveOneChild) {
    BST<int> tree;
    tree.Insert(10);
    tree.Insert(5);
    tree.Insert(3); // 3 is left child of 5

    EXPECT_TRUE(tree.Remove(5));
    EXPECT_EQ(tree.Search(5), std::nullopt);
    EXPECT_EQ(tree.Search(3), std::optional<int>(3));
}

TEST(BSTTest, RemoveTwoChildren) {
    BST<int> tree;
    tree.Insert(20);
    tree.Insert(10);
    tree.Insert(30);
    tree.Insert(25);
    tree.Insert(35);

    EXPECT_TRUE(tree.Remove(30));
    EXPECT_EQ(tree.Search(30), std::nullopt);
    EXPECT_TRUE(tree.Search(25).has_value() || tree.Search(35).has_value());
}

TEST(BSTTest, RemoveNonExistent) {
    BST<int> tree;
    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);

    EXPECT_FALSE(tree.Remove(99));
    EXPECT_EQ(tree.Search(1), std::optional<int>(1));
    EXPECT_EQ(tree.Search(2), std::optional<int>(2));
    EXPECT_EQ(tree.Search(3), std::optional<int>(3));
}

TEST(BSTTest, FullClear) {
    BST<int> tree;
    tree.Insert(50);
    tree.Insert(25);
    tree.Insert(75);

    EXPECT_TRUE(tree.Remove(50));
    EXPECT_TRUE(tree.Remove(25));
    EXPECT_TRUE(tree.Remove(75));

    EXPECT_EQ(tree.Search(50), std::nullopt);
    EXPECT_EQ(tree.Search(25), std::nullopt);
    EXPECT_EQ(tree.Search(75), std::nullopt);
}

TEST(BSTTest, DuplicateInsert) {
    BST<int> tree;
    tree.Insert(10);
    tree.Insert(10);  // Duplicate

    EXPECT_EQ(tree.Search(10), std::optional<int>(10));
    EXPECT_TRUE(tree.Remove(10));
    EXPECT_EQ(tree.Search(10), std::nullopt);

    // Second remove should fail if duplicates weren't added
    EXPECT_FALSE(tree.Remove(10));
}

TEST(BSTTest, RemoveRootWithTwoChildren) {
    BST<int> tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    EXPECT_TRUE(tree.Remove(50)); // root with two children
    EXPECT_EQ(tree.Search(50), std::nullopt);
}

TEST(BSTTest, SequentialInsertRemove) {
    BST<int> tree;
    for (int i = 1; i <= 10; ++i) {
        tree.Insert(i);
    }

    for (int i = 1; i <= 10; ++i) {
        EXPECT_EQ(tree.Search(i), std::optional<int>(i));
    }

    for (int i = 1; i <= 10; ++i) {
        EXPECT_TRUE(tree.Remove(i));
        EXPECT_EQ(tree.Search(i), std::nullopt);
    }
}

TEST(BSTTest, RemoveInReverseOrder) {
    BST<int> tree;
    std::vector<int> values = {10, 5, 15, 3, 7, 12, 18};

    for (int val : values) {
        tree.Insert(val);
    }

    std::reverse(values.begin(), values.end());
    for (int val : values) {
        EXPECT_TRUE(tree.Remove(val));
        EXPECT_EQ(tree.Search(val), std::nullopt);
    }
}

TEST(BSTTest, RemoveRootRepeatedly) {
    BST<int> tree;
    std::vector<int> values = {10, 5, 15, 3, 7, 12, 18};

    for (int val : values) {
        tree.Insert(val);
    }

    while (tree.Search(values[0]).has_value()) {
        EXPECT_TRUE(tree.Remove(values[0]));
        values.erase(values.begin()); // simulate new root
    }
}