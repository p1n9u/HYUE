package com.example.week0901;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class SubActivity extends AppCompatActivity {

    TextView textView;
    Button button;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub);

        Intent intent = getIntent();
        String data1 = intent.getStringExtra("kScore");
        int kScore = Integer.parseInt(data1);
        String data2 = intent.getStringExtra("mScore");
        int mScore = Integer.parseInt(data2);

        int sum = kScore + mScore;
        double avg = sum/2.0;
        String data3 = String.format("%.2f", avg);

        textView = (TextView)findViewById(R.id.textView);
        textView.setText("총 합은 " + sum + "점 이고, 평균은 " + data3 + "점 입니다.");

        button = (Button)findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });

    }
}
