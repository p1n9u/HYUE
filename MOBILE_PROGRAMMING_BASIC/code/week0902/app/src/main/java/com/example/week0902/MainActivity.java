package com.example.week0902;

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

    // bundle로 전달
    public void onClick(View v) {
        Intent intent = new Intent(MainActivity.this, SubActivity.class);
        editText1 = (EditText)findViewById(R.id.editText1);
        editText2 = (EditText)findViewById(R.id.editText2);

        Bundle bundle = new Bundle();
        bundle.putString("kScore", editText1.getText().toString());
        bundle.putString("mScore", editText2.getText().toString());
        intent.putExtras(bundle);

        startActivity(intent);
    }
}
