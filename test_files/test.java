public class BinaryTree{
    public static void main(String[] a){
	System.out.println(new BT().Start());
    }
}


// This class invokes the methods to create a tree,
// insert, delete and serach for  elements on it
class BT {

    public int Start(){
		Tree root ;
		root = new Tree();

		boolean ntb ;

		ntb = root.Init();

		return 0 ;
    }

}

class Tree{


    // Initialize a node with a key value and no children
    public boolean Init(){

		return true ;
    }



}


