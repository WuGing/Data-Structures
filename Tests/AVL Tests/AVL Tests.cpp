#include "pch.h"
#include "CppUnitTest.h"

#include "../../Projects/AVL/AVL.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTests
{
	TEST_CLASS(AVLTests)
	{
	public:

		TEST_METHOD(UnOrderedPrintTests1) 
		{
			AVL tree;

			tree.BST::Insert(1);
			tree.BST::Insert(2);
			tree.BST::Insert(3);		// rotate left
			tree.BST::Insert(4);
			tree.BST::Insert(5);		// rotate left

			Assert::AreEqual(std::string("2 1 4 3 5"),
				tree.PreOrder());

			Assert::AreEqual(std::string("1 2 3 4 5"),
				tree.InOrder());

			Assert::AreEqual(std::string("1 3 5 4 2"),
				tree.PostOrder());

			Node* test04 = tree.Search(4);
			Node* test05 = tree.Search(5);
			Node* test01 = tree.Search(1);
			Node* test02 = tree.Search(2);

			Assert::AreEqual(2, test04->height);
			Assert::AreEqual(1, test05->height);
			Assert::AreEqual(1, test01->height);
			Assert::AreEqual(3, test02->height);
		}

		TEST_METHOD(BalanceRotateLeftTest)
		{
			AVL tree;

			tree.BST::Insert(1);
			tree.BST::Insert(3);
			tree.BST::Insert(5);

			Assert::AreEqual(std::string("3 1 5"),
				tree.PreOrder());

			Assert::AreEqual(std::string("1 3 5"),
				tree.InOrder());

			Assert::AreEqual(std::string("1 5 3"),
				tree.PostOrder());
		}

		TEST_METHOD(BalanceRotateRightTest)
		{
			AVL tree;

			tree.BST::Insert(5);
			tree.BST::Insert(3);
			tree.BST::Insert(1);

			Assert::AreEqual(std::string("3 1 5"),
				tree.PreOrder());

			Assert::AreEqual(std::string("1 3 5"),
				tree.InOrder());

			Assert::AreEqual(std::string("1 5 3"),
				tree.PostOrder());
		}

		TEST_METHOD(BalanceRotateLeftRightTest)
		{
			AVL tree;

			tree.BST::Insert(3);
			tree.BST::Insert(5);
			tree.BST::Insert(4);

			Assert::AreEqual(std::string("4 3 5"),
				tree.PreOrder());

			Assert::AreEqual(std::string("3 4 5"),
				tree.InOrder());

			Assert::AreEqual(std::string("3 5 4"),
				tree.PostOrder());
		}

		TEST_METHOD(BalanceRotateRightLeftTest)
		{
			AVL tree;

			tree.BST::Insert(5);
			tree.BST::Insert(3);
			tree.BST::Insert(4);

			Assert::AreEqual(std::string("4 3 5"),
				tree.PreOrder());

			Assert::AreEqual(std::string("3 4 5"),
				tree.InOrder());

			Assert::AreEqual(std::string("3 5 4"),
				tree.PostOrder());
		}

		TEST_METHOD(SearchTest)
		{
			AVL tree;

			tree.BST::Insert(50);
			tree.BST::Insert(75);
			tree.BST::Insert(25);
			tree.BST::Insert(100);
			tree.BST::Insert(0);
			tree.BST::Insert(35);
			tree.BST::Insert(95);
			tree.BST::Insert(5);
			tree.BST::Insert(4);
			tree.BST::Insert(62);

			// let's make sure the tree is in the right order
			Assert::AreEqual(std::string("50 25 4 0 5 35 95 75 62 100"),
				tree.PreOrder());

			Assert::AreEqual(std::string("0 4 5 25 35 50 62 75 95 100"),
				tree.InOrder());

			Assert::AreEqual(std::string("0 5 4 35 25 62 75 100 95 50"),
				tree.PostOrder());

			// ensure we don't return for nodes that don't exist
			Assert::IsNull(tree.Search(7));
			Assert::IsNull(tree.Search(64));

			// retrieve nodes
			Node* test75 = tree.Search(75);
			Node* test95 = tree.Search(95);
			Node* test50 = tree.Search(50);
			Node* test62 = tree.Search(62);
			Node* test35 = tree.Search(35);
			Node* test04 = tree.Search(4);
			Node* test25 = tree.Search(25);

			// check that returned nodes have the correct height
			Assert::AreEqual(2, test75->height);
			Assert::AreEqual(3, test95->height);
			Assert::AreEqual(4, test50->height);
			Assert::AreEqual(1, test62->height);
			Assert::AreEqual(1, test35->height);
			Assert::AreEqual(2, test04->height);
			Assert::AreEqual(3, test25->height);
		}
	};
}
