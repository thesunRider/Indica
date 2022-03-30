package com.elementx.indica;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Messenger;
import android.util.Log;
import android.widget.CompoundButton;
import android.widget.Switch;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.HttpResponse;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import java.net.*;


public class MainActivity extends AppCompatActivity {
    private Switch left_switch;
    private Switch right_switch;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        left_switch = (Switch) findViewById(R.id.ind_left);
        right_switch = (Switch) findViewById(R.id.ind_right);

        right_switch.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                try {

                    RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
                    String url = getString(R.string.url_ind);
                    StringRequest stringRequest;

                    if (isChecked) {
                        stringRequest  = new StringRequest(Request.Method.GET, url +"?indic=1&swtch=1",null,null);
                        queue.add(stringRequest);
                    } else {
                        stringRequest  = new StringRequest(Request.Method.GET, url+"?indic=1&swtch=0",null,null);
                        queue.add(stringRequest);
                    }

                }catch (Exception e){
                    e.printStackTrace();
                }


            }
        });

        left_switch.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

                try {

                    RequestQueue queue = Volley.newRequestQueue(getApplicationContext());
                    String url = getString(R.string.url_ind);
                    StringRequest stringRequest;

                    if (isChecked) {
                        stringRequest  = new StringRequest(Request.Method.GET, url +"?indic=0&swtch=1",null,null);
                        queue.add(stringRequest);
                    } else {
                        stringRequest  = new StringRequest(Request.Method.GET, url+"?indic=0&swtch=0",null,null);
                        queue.add(stringRequest);
                    }

                }catch (Exception e){
                    e.printStackTrace();
                }


            }
        });



    }

}