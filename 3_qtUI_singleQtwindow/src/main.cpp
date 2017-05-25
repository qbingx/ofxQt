#include "QtGuiClass.h"
#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include <QApplication>

#include "ofAppQtWindow.h"

int main( )
{
	ofQtGLWindowSettings settings;

	settings.title = "Render 1";
	settings.width = 400;
	settings.height = 200;
	settings.setPosition(ofVec2f(500, 100));
	settings.resizable = true;
//	settings.decorated = false;
	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>();
	mainWindow->createQtApp();
	mainWindow->setup(settings);
	shared_ptr<ofApp> app(new ofApp);

	ofGLFWWindowSettings settings2;
	settings2.title = "Render 2";
	settings2.width = 300;
	settings2.height = 300;
	settings2.setPosition(ofVec2f(1100, 100));
	settings2.resizable = false;
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings2);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	app->gui = guiApp;

	QtGuiClass w;

    app->ui = &w;
	guiApp->ui = &w;

    w.show();
//	a.exec(); // do not use

	ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, app);
	ofRunMainLoop();//

	////////////////////////////////
	//	other ways of creating ofAppQtWindow
	////////////////////////////////
	/*
	ofAppQtWindow window;
	window.createQtApp();
	//	window.setMultiDisplayFullscreen(true);
	ofSetupOpenGL(&window, 800, 400, OF_WINDOW);
	ofRunApp(new ofApp);
	*/
	// -- or
	/*
	shared_ptr<ofApp> app = make_shared<ofApp>();
	ofAppQtWindow window;
	window.createQtApp();
	ofSetupOpenGL(&window, 800, 400, OF_WINDOW);
	ofRunApp(app);
	*/
}
