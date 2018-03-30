package cc.openframeworks.androidScreenRecording;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

import cc.openframeworks.OFActivity;
import cc.openframeworks.OFAndroid;
import cc.openframeworks.OFAndroidLifeCycle;

/**
 * Created by dan on 3/25/2018.
 */

public class ButtonActivity extends cc.openframeworks.OFActivity{

    public Button myButton;
    public Button recButton;

    public boolean bRecording = false;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        recButton = findViewById(R.id.record_button);
        recButton.setBackground(getDrawable(R.drawable.record));
        OFAndroidLifeCycle.getGLView();

    }

    @Override
    public void onDetachedFromWindow() {
    }

    public void myButtonClicked(View v){
        OFAndroid.onMenuItemSelected("my_button");
    }


    public void recordButtonClicked(View v){
//        OFAndroid.onMenuItemSelected("record_button");
        if(!bRecording) {
            recButton.setBackground(getDrawable(R.drawable.stop));
            bRecording = true;
            OFAndroidLifeCycle.getGLView().prepareRec(getTexID());
            OFAndroidLifeCycle.getGLView().startVideo();
        }else{
            recButton.setBackground(getDrawable(R.drawable.record));
            bRecording = false;
            OFAndroidLifeCycle.getGLView().stopVideo();
        }
    }
    // Menus
    // http://developer.android.com/guide/topics/ui/menus.html
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Create settings menu options from here, one by one or infalting an xml
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // This passes the menu option string to OF
        // you can add additional behavior from java modifying this method
        // but keep the call to OFAndroid so OF is notified of menu events
        if(OFAndroid.menuItemSelected(item.getItemId())){

            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    public native int getTexID();

    @Override
    public boolean onPrepareOptionsMenu (Menu menu){
        // This method is called every time the menu is opened
        //  you can add or remove menu options from here
        return  super.onPrepareOptionsMenu(menu);
    }


}
