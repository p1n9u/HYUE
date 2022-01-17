package com.example.week0901;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    EditText editText1, editText2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    // intent로 전달
    public void onClick(View v) {
        Intent intent = new Intent(MainActivity.this, SubActivity.class);
        editText1 = (EditText)findViewById(R.id.editText1);
        editText2 = (EditText)findViewById(R.id.editText2);
        intent.putExtra("kScore", editText1.getText().toString());
        intent.putExtra("mScore", editText2.getText().toString());
        startActivity(intent);
    }
}
