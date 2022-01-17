package com.example.week1301;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class ParentActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_parent);
    }

    public void moveChild(View view) {
        Intent intent = new Intent(ParentActivity.this, ChildActivity.class);
        startActivity(intent);
    }
}
