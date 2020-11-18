package ru.arina.arina_todolist;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.widget.AppCompatImageButton;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.textfield.TextInputEditText;

import java.util.ArrayList;

public class RecyclerViewAdapter extends RecyclerView.Adapter<RecyclerViewAdapter.ToDoViewHolder> implements OnTaskAcceptListener, OnTaskCancelListener{

    private final OnTaskCancelListener cancelListener;
    private final OnTaskAcceptListener acceptListener;
    private final ArrayList<String> data;
    private boolean isCreatingNewTask = false;

    public RecyclerViewAdapter(ArrayList<String> data, OnTaskAcceptListener acceptListener, OnTaskCancelListener cancelListener) {
        this.acceptListener = acceptListener;
        this.cancelListener = cancelListener;
        this.data = data;
    }

    public void showNewTaskInput() {
        isCreatingNewTask = true;
    }

    public void hideNewTaskInput() {
        isCreatingNewTask = false;
    }

    @NonNull
    @Override
    public ToDoViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View view = inflater.inflate(R.layout.recycler_view_item, parent, false);
        return new ToDoViewHolder(view, viewType == 0);
    }

    @Override
    public void onBindViewHolder(@NonNull ToDoViewHolder holder, int position) {

        if (isCreatingNewTask) {
            if (position == 0) {
                holder.BindData("", this, this);
                return;
            }
            holder.BindData(data.get(position - 1), this, this);
        } else {
            holder.BindData(data.get(position), this, this);
        }
    }

    @Override
    public int getItemCount() {
        if (data == null) return 0;
        if (isCreatingNewTask) return data.size() + 1;
        return data.size();
    }

    @Override
    public int getItemViewType(int position) {
        if (isCreatingNewTask && position == 0) return 1;
        return 0;
    }

    @Override
    public void OnAccept(String task) {
        acceptListener.OnAccept(task);
    }

    @Override
    public void OnCancel(int position) {
        cancelListener.OnCancel(position);
    }

    static class ToDoViewHolder extends RecyclerView.ViewHolder {

        TextInputEditText editText;
        TextView titleTextView;
        AppCompatImageButton cancelButton;
        AppCompatImageButton acceptButton;
        OnTaskCancelListener cancelListener;
        OnTaskAcceptListener acceptListener;
        boolean finalTitle;

        public ToDoViewHolder(@NonNull View itemView, boolean finalTitle) {
            super(itemView);
            editText = itemView.findViewById(R.id.recycler_view_item_edit_text);
            titleTextView = itemView.findViewById(R.id.recycler_view_item_text_view);
            cancelButton = itemView.findViewById(R.id.recycler_view_item_cancel_image_button);
            acceptButton = itemView.findViewById(R.id.recycler_view_item_accept_image_button);
            this.finalTitle = finalTitle;
        }

        public void BindData(String taskTitle, OnTaskAcceptListener acceptListener, OnTaskCancelListener cancelListener) {
            this.acceptListener = acceptListener;
            this.cancelListener = cancelListener;


            cancelButton.setOnClickListener(v -> {
                cancelListener.OnCancel(getAdapterPosition());
            });

            if (finalTitle) {
                editText.setVisibility(View.GONE);
                titleTextView.setVisibility(View.VISIBLE);
                titleTextView.setText(taskTitle);
                acceptButton.setVisibility(View.GONE);
            } else {
                acceptButton.setVisibility(View.VISIBLE);
                editText.setVisibility(View.VISIBLE);
                titleTextView.setVisibility(View.GONE);
                editText.setText(taskTitle);
                acceptButton.setOnClickListener( v-> {
                    acceptListener.OnAccept(editText.getText().toString());
                });
            }
        }
    }
}
