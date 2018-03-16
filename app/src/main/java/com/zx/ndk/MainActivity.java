package com.zx.ndk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    public String zxname = "我是大雄";

    private int[] soure= {6,2,9,4,0};


    TextView tvField;
    TextView tvMethodString;
    TextView tvMethodStringStatic;
    TextView tvMethodInt;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

         tvField = findViewById(R.id.tv_field);
         tvMethodString = findViewById(R.id.tv_method_string);
         tvMethodStringStatic = findViewById(R.id.tv_method_string_static);
         tvMethodInt = findViewById(R.id.tv_method_int);

        tvField.setText(updateField());
        tvMethodString.setText(updateMethodString());
        tvMethodStringStatic.setText(updateMethodStaticString());


            exception();

    }


    public native String stringFromJNI();
    public native String updateField();
    public native String updateMethodString();
    public native String updateMethodStaticString();
    //引用解决的问题：通知JVM虚拟机回收JNI对象
    public native void getLocal();
    //异常处理，c++的异常，Java代码是无法捕获的
    public native void exception();
    //缓存策略，对象的生命周期
    public static native String cache();


    public String getWork() {
        return "工作中。。。";
    }

    public static String getWorks() {
        return "工作中哇哇哇。。。";
    }

    public int getAge() {
        return 15;
    }
}
