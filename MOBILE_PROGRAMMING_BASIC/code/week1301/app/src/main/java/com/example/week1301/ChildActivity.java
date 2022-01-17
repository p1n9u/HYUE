package com.example.week1301;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class ChildActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_child);
    }

    public void moveMain(View view) {
        Intent intent = new Intent(ChildActivity.this, MainActivity.class);
        startActivity(intent);
    }
}
