public class Factorial {
    public static void main(String[] a) {
        System.out.println(new classtest().aFunc());
    }
}

class classtest {
    int a;
    boolean b;
    int[] c;
    classdata d;

    public int aFunc() {
        e = a; //fail
        a = d.yFunc();//fail
        a = d.zFunc();//fail
        return a;
    }

    public boolean bFunc() {
        b = d.zzFunc(); //fail
        a = d.xFunc();
        b = this.zFunc(); //fail
        b = this.aFunc();
        b = d.xFunc();//fail
        b = d.zFunc();//fail
        return b;
    }

    public int[] cFunc() {
        c = d.xFunc();//fail
        c = d.yFunc();//fail
        return c;
    }

    public classdata dFunc() {
        d = d.xFunc();//fail
        d = d.yFunc();//fail
        d = d.zFunc();//fail
        d = d;//accept
        return d;
    }

    public boolean EFUNC() {
        a = b;//fail
        a = c;//fail
        a = d;//fail
        b = a;//fail
        b = c;//fail
        b = d;//fail
        c = a;//fail
        c = b;//fail
        c = d;//fail
        return false;
    }

}

class thatdoExist {
    int a;
}

class classdata {
    int x;
    boolean y;
    int[] z;
    classthatdoesntExist pem;//fail
    thatdoExist pen;

    public int xFunc() {
        return x;
    }

    public boolean yFunc() {
        return y;
    }

    public int[] zFunc() {
        return z;
    }
}

class VarUsedBeforeDefinition {
    int a;

    public int b(int b) {
        a = 10; // correct
        b = 10; // correct
        //c = 11;
        //int c;

        return a;
    }
}
