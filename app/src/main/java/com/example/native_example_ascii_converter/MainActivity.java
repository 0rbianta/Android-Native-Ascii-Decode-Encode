package com.example.native_example_ascii_converter;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {


    static {
        System.loadLibrary("native_1");
    }

    private EditText input,output,input_d,output_d;


    private native String text2ascii(String plain_text);
    private native String ascii2text(String asciis_j);


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        output = findViewById(R.id.output);
        input = findViewById(R.id.input);
        input_d = findViewById(R.id.input_d);
        output_d = findViewById(R.id.output_d);

    }

    public void convert(View v){

        output.setText(text2ascii(input.getText().toString()));

    }

    public void convert_d(View v){

        output_d.setText(ascii2text(input_d.getText().toString()));

    }


}