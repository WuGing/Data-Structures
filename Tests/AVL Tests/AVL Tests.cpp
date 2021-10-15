#include "pch.h"
#include "CppUnitTest.h"

#include "../../Projects/AVL/AVL.cpp"
#include "../../Projects/AVL/Node.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTests
{
	TEST_CLASS(AVLTests)
	{
	public:
		
		TEST_METHOD(OrderPrintTests1)
		{
			AVL tree;

			tree.Insert(4);
			tree.Insert(5);
			tree.Insert(2);
			tree.Insert(3);
			tree.Insert(1);

			Assert::AreEqual(std::string("4 2 1 3 5"),
				tree.PreOrder());

			Assert::AreEqual(std::string("1 2 3 4 5"),
				tree.InOrder());

			Assert::AreEqual(std::string("1 3 2 5 4"),
				tree.PostOrder());

			Node* test04 = tree.Search(4);
			Node* test05 = tree.Search(5);
			Node* test01 = tree.Search(1);
			Node* test02 = tree.Search(2);

			Assert::AreEqual(3, test04->height);
			Assert::AreEqual(1, test05->height);
			Assert::AreEqual(1, test01->height);
			Assert::AreEqual(2, test02->height);
		}

		TEST_METHOD(OrderPrintTests2)
		{
			AVL tree;

			tree.Insert(25);
			tree.Insert(15);
			tree.Insert(50);
			tree.Insert(10);
			tree.Insert(22);
			tree.Insert(35);
			tree.Insert(70);
			tree.Insert(4);
			tree.Insert(12);
			tree.Insert(31);
			tree.Insert(44);
			tree.Insert(18);
			tree.Insert(24);
			tree.Insert(66);
			tree.Insert(90);

			Assert::AreEqual(std::string("25 15 10 4 12 22 18 24 50 35 31 44 70 66 90"),
				tree.PreOrder());

			Assert::AreEqual(std::string("4 10 12 15 18 22 24 25 31 35 44 50 66 70 90"),
				tree.InOrder());

			Assert::AreEqual(std::string("4 12 10 18 24 22 15 31 44 35 66 90 70 50 25"),
				tree.PostOrder());

			Node* test25 = tree.Search(25);
			Node* test15 = tree.Search(15);
			Node* test35 = tree.Search(35);
			Node* test31 = tree.Search(31);

			Assert::AreEqual(4, test25->height);
			Assert::AreEqual(3, test15->height);
			Assert::AreEqual(2, test35->height);
			Assert::AreEqual(1, test31->height);
		}

		TEST_METHOD(UnOrderedPrintTests1) 
		{
			AVL tree;

			tree.Insert(1);
			tree.Insert(2);
			tree.Insert(3);		// rotate left
			tree.Insert(4);
			tree.Insert(5);		// rotate left

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

			tree.Insert(1);
			tree.Insert(3);
			tree.Insert(5);

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

			tree.Insert(5);
			tree.Insert(3);
			tree.Insert(1);

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

			tree.Insert(3);
			tree.Insert(5);
			tree.Insert(4);

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

			tree.Insert(5);
			tree.Insert(3);
			tree.Insert(4);

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

			tree.Insert(50);
			tree.Insert(75);
			tree.Insert(25);
			tree.Insert(100);
			tree.Insert(0);
			tree.Insert(35);
			tree.Insert(95);
			tree.Insert(5);
			tree.Insert(4);
			tree.Insert(62);

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
