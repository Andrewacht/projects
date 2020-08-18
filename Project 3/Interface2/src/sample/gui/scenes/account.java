package sample.gui.scenes;

import cz.kamenitxan.sceneswitcher.SceneSwitcher;

public class account {
    public void logout(){
        SceneSwitcher.getInstance().loadScene("Login", "cs");
    }
}
