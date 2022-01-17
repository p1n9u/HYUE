package com.example.week0701;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Button button;
    EditText editText1, editText2, editText3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText1 = (EditText)findViewById(R.id.editText);
        editText2 = (EditText)findViewById(R.id.editText2);
        editText3 = (EditText)findViewById(R.id.editText3);
        button = (Button)findViewById(R.id.button);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String data1 = editText1.getText().toString();
                int kScore = Integer.parseInt(data1);

                String data2 = editText2.getText().toString();
                int mScore = Integer.parseInt(data2);

                String data3 = editText3.getText().toString();
                int eScore = Integer.parseInt(data3);

                int sum = kScore + mScore + eScore;
                // String data4 = Integer.toString(sum);

                double avg = sum/3.0;
                String data5 = String.format("%.2f", avg);

                editText1.setText("국어는" + kScore + "점 입니다.");
                editText2.setText("수학은" + mScore + "점 입니다.");
                editText3.setText("영어는" + eScore + "점 입니다.");
                Toast.makeText(getApplicationContext(),"총점은" + sum + "점 이고, 평균은" + data5 + "점 입니다.", Toast.LENGTH_LONG).show();
            }
        });
    }
}
