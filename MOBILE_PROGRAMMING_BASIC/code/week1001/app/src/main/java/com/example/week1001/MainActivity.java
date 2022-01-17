package com.example.week1001;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AnalogClock;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    AnalogClock analogTime;
    TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        analogTime = (AnalogClock)findViewById(R.id.analog_clock);
        textView = (TextView)findViewById(R.id.textView);

        analogTime.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final Calendar c = Calendar.getInstance();
                int mHour = c.get((Calendar.HOUR_OF_DAY));
                int mMinute = c.get((Calendar.MINUTE));
                textView.setText("지금 시간은 " + mHour + "시 " + mMinute + "분 입니다.");
                Toast.makeText(getApplicationContext(), "지금 시간은 " + mHour + "시 " + mMinute + "분 입니다.", Toast.LENGTH_LONG).show();
            }
        });
    }

}
