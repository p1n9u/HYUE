package com.example.week1201;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TabHost;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        setTitle("탭호스트 예제");

        TabHost tabHost = (TabHost)findViewById(R.id.tabhost1);
        tabHost.setup();

        // Tab Spec Tag를 가진 TabSpec 객체 생성
        TabHost.TabSpec tab1 = tabHost.newTabSpec("A");
        // 탭 리소스 id와 문자열 지정
        tab1.setContent(R.id.tab1).setIndicator("음악별");
        // TabHost에 추가
        tabHost.addTab(tab1);

        TabHost.TabSpec tab2 = tabHost.newTabSpec("B");
        tab2.setContent(R.id.tab2).setIndicator("앨범별");
        tabHost.addTab(tab2);

        TabHost.TabSpec tab3 = tabHost.newTabSpec("C");
        tab3.setContent(R.id.tab3).setIndicator("가수별");
        tabHost.addTab(tab3);

    }
}
