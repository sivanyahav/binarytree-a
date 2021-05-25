#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace std;
using namespace ariel;
int NUM_TEST=20;

 /****CHECK ADD_ROOT FUNC*******/
TEST_CASE("add_root function"){

    BinaryTree<int> t;
    t.add_root(1);

    for (int i = 0; i < NUM_TEST; i++)
    {
        CHECK_NOTHROW(t.add_root(i));
        CHECK_EQ(i,  *t.begin_preorder());
    }

    CHECK_NOTHROW(t.add_root(1).add_root(2).add_root(3));

    /*tree of char---> Generic testing*/
    BinaryTree<char> c;
    c.add_root('1');

   
    for (int i = 0; i < NUM_TEST; i++)
    {
        CHECK_NOTHROW(c.add_root((char)i));
        CHECK_EQ((char)i,  *t.begin_preorder());
    }

    CHECK_NOTHROW(c.add_root('1').add_root('2').add_root('3'));

}

 /****CHECK ADD_LEFT_CHILD FUNC*******/
TEST_CASE("add left child"){
    BinaryTree<int> t;
    CHECK_THROWS(t.add_left(1,2));
    t.add_root(0);
    CHECK_NOTHROW(t.add_left(0,1).add_left(1,2).add_left(2,3));
   
    /** The tree:
     *              0
     *             /
     *            1
     *           /
     *          2
     *         /
     *        3
     */

    string it_inorder= "";
    for(auto it= t.begin_inorder(); it!=t.end_inorder(); ++it){
        it_inorder+=to_string(*it);
    }
    CHECK_EQ(it_inorder, "3210");

    /*tree of char---> Generic testing*/
    BinaryTree<char> c;
    CHECK_THROWS(c.add_left('1','2'));
    t.add_root('0');
    CHECK_NOTHROW(t.add_left('0','1').add_left('1','2').add_left('2','3'));
   
    /** The tree:
     *              0
     *             /
     *            1
     *           /
     *          2
     *         /
     *        3
     */

    it_inorder= "";
    for(auto it= t.begin_inorder(); it!=t.end_inorder(); ++it){
        it_inorder+=*it;
    }
    CHECK_EQ(it_inorder, "3210");
}

 /****CHECK ADD_RIGHT_CHILD FUNC*******/
TEST_CASE("add right child"){
    BinaryTree<int> t;
    
     /** The tree:
     *       0
     *        \
     *         1
     *          \
     *           2
     *            \
     *             3
     */
}