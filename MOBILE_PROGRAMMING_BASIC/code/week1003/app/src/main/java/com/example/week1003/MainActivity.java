package com.example.week1003;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.TextView;
import android.widget.TimePicker;

import java.sql.Time;

public class MainActivity extends AppCompatActivity {

    TimePicker timepicker;
    DatePicker datepicker;
    Button button;
    TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        timepicker = (TimePicker)findViewById(R.id.timepicker);
        datepicker = (DatePicker)findViewById(R.id.datepicker);
        button = (Button)findViewById(R.id.button);
        textView = (TextView)findViewById(R.id.textView);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText(datepicker.getYear() + "년 " + datepicker.getMonth() + "월 " + datepicker.getDayOfMonth() + "일 " + timepicker.getHour() + "시 " + timepicker.getMinute() + "분을 선택");
            }
        });
    }
}
