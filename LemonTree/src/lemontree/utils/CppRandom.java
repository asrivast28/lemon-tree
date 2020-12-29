package lemontree.utils;


public class CppRandom {

  static {
    System.loadLibrary("CppRandom");
  }

  public static native void setSeed(int seed);

  public static native int nextInteger(int lower, int upper);

  public static native double nextDouble();

  public static void main(String[] args) {
    setSeed(0);
    double test = nextDouble();
    System.out.println(test);
  }
}
