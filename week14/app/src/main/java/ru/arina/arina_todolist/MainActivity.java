package ru.arina.arina_todolist;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.view.inputmethod.InputMethodManager;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import java.util.ArrayList;
import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    private FloatingActionButton addFab;
    private RecyclerViewAdapter adapter;
    private ArrayList<String> data;
    private boolean isCreating = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = findViewById(R.id.main_toolbar);
        setSupportActionBar(toolbar);



        RecyclerView recyclerView = findViewById(R.id.main_recycler_view);
        addFab = findViewById(R.id.main_fab);
        String restoredData = getSharedPreferences("main", MODE_PRIVATE).getString("data", null);
        if (restoredData != null && !restoredData.equals("")) data = new ArrayList<>(Arrays.asList(restoredData.split("\\[\\^]")));
        else data = new ArrayList<>();
        adapter = new RecyclerViewAdapter(data, this::acceptTask, this::deleteTask);
        recyclerView.setAdapter(adapter);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        recyclerView.addItemDecoration(new DividerItemDecoration(this, DividerItemDecoration.VERTICAL));
        addFab.setOnClickListener(v -> {
            addFab.setVisibility(View.GONE);
            adapter.showNewTaskInput();
            adapter.notifyItemInserted(0);
            isCreating = true;
        });
    }

    private void acceptTask(String task) {
        data.add(0, task);
        adapter.hideNewTaskInput();
        adapter.notifyItemChanged(0);
        addFab.setVisibility(View.VISIBLE);
        isCreating = false;
        InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(addFab.getWindowToken(), 0);
    }

    private void deleteTask(int position) {
        adapter.hideNewTaskInput();
        if (isCreating && position == 0) {
            addFab.setVisibility(View.VISIBLE);
            isCreating = false;
        } else {
            data.remove(position);
        }
        adapter.notifyItemRemoved(position);
    }

    @Override
    protected void onPause() {
        StringBuilder builder = new StringBuilder();
        for (String task: data) {
            builder.append(task);
            builder.append("[^]");
        }
        SharedPreferences.Editor prefs = getSharedPreferences("main", MODE_PRIVATE).edit();
        prefs.putString("data", builder.toString());
        prefs.apply();
        super.onPause();
    }
}