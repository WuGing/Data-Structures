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
		}

		TEST_METHOD(UnOrderedPrintTests1) 
		{
			AVL tree;

			tree.Insert(1);
			tree.Insert(2);
			tree.Insert(3);
			tree.Insert(4);
			tree.Insert(5);

			Assert::AreEqual(std::string("2 1 4 3 5"),
				tree.PreOrder());

			Assert::AreEqual(std::string("1 2 3 4 5"),
				tree.InOrder());

			Assert::AreEqual(std::string("1 3 5 4 2"),
				tree.PostOrder());
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

	};
}
