public class Factorial {
    public static void main(String[] a) {
        System.out.println(new classdata().xyFunc());
    }
}

class classtest {
    int a;
}

class classdata {
    int x;
    boolean y;
    int[] z;
    classdata xyz;

    public int xyFunc() {
        return y;
    }//fail

    public int xzFunc() {
        return z;
    }//fail

    public boolean yxFunc() {
        return x;
    }//fail

    public boolean yzFunc() {
        return this.zxFunc();
    }//fail

    public int[] zxFunc() {
        return x;
    }//fail

    public int[] zyFunc() {
        return this.yxFunc();
    }//fail

    public int swFunc() {
        return z[this.yzFunc()];//fail
    }

}
