#pragma once

#include "ofMain.h"
#include "ofxTimeMeasurements.h"
#include "Constants.h"
#include "Spring.h"
#include "ofxRemoteUIServer.h"
#include "ofFboBlur.h"
#include "Parser.h"

// missing name "WTF_BUG" !!

class testApp : public ofBaseApp{
	
	public:
	
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h){};
		void dragEvent(ofDragInfo dragInfo){};
		void gotMessage(ofMessage msg){};

		void exit();

		void recursiveFillVectorAndSprings(Node * node, int &level, int maxLevel,
										   vector<Node*> &chosenNodes, vector<Spring*> &springs);

		void calcForces(vector<Node*> &chosenNodes, vector<Spring*> &springs);
		void updateNodeForces(vector<Node*> &chosenNodes);
		void fillMesh(vector<Node*> &chosenNodes, ofMesh & linesMesh, ofMesh & ptsMesh);


		Parser parser;

		vector<Node*> speciesAll; //access by ID, contains duplicates
		map<string, Node*> nodesByName;

		vector<Node*> chosenNodes;
		vector<Spring*> springs;

		Node* treeRoot;

		ofMesh lines;
		ofMesh nodes;
		ofMesh forces;

		ofEasyCam cam;

		float SPRING_LENGTH;
		float SPRING_FORCE;
		float REPULSION_FORCE;
		float REPULSION_DIST;
		float FRICTION;
		bool drawNames;
		int nameFilter;
		bool updateMesh;
		bool repellNN;
		float repelNNGain;
		float repelMyChildrenGain;
		float repelChildChildGain;
		float repelChildChildDistGain;
		bool drawForces;

		float lineWidth;
		float pointSize;
		float lineAlpha;
		float pointAlpha;
		float nameAlpha;

		int blurIterations;
		float blurOffset;
		int blurOverlayGain;
		int numBlurOverlays;

		ofFboBlur gpuBlur;

};
