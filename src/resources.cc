#include <iostream>
#include "resources.hh"
using namespace std;

namespace resources {
	string dirRoot = "";
	map<string, Texture> textures;
	map<string, SoundBuffer> soundFile;
	Font font;
	string highScoresFileName;

	void throwFileError(string fileName) {
		throw runtime_error(
			"Could not find resource '"
			+ fileName
			+ "', try reinstalling."
		);
	}

	void initDirRoot() {
		string devDirectory = "res/resource/";
		string releaseDirectory = "resource/";
		string devTest = devDirectory + defines::TEXTURE_FILE_NAMES[0] + defines::IMAGE_FILE_TYPE;
		string releaseTest = releaseDirectory + defines::TEXTURE_FILE_NAMES[0] + defines::IMAGE_FILE_TYPE;
		Texture test;
		if (test.loadFromFile(releaseTest)) {
			resources::dirRoot = releaseDirectory;
		} else if (test.loadFromFile(devTest)) {
			resources::dirRoot = devDirectory;
		} else {
			throwFileError(defines::TEXTURE_FILE_NAMES[0]);
		}
	}


	void loadTextures() {
		string fullFileName = "";
		for (string fileName : defines::TEXTURE_FILE_NAMES) {
			fullFileName = resources::dirRoot + fileName + defines::IMAGE_FILE_TYPE;
			resources::textures.emplace(fileName, Texture{});
			if (!resources::textures[fileName].loadFromFile(fullFileName)) {
				throwFileError(fileName);
			}
		}
	}

	void loadFonts() {
		string fontFileName = resources::dirRoot + defines::FONT_FILE_NAME + defines::FONT_FILE_TYPE;
		if (!font.loadFromFile(fontFileName)) {
			throwFileError(defines::FONT_FILE_NAME);
		}
	}

	void generateHighScoresString() {
		highScoresFileName = resources::dirRoot + defines::SCORES_FILE_NAME + defines::SCORES_FILE_TYPE;
	}

	void loadSounds() {
		string fullFileName = "";
		for (string fileName : defines::SOUND_FILE_NAMES) {
			fullFileName = resources::dirRoot + fileName + defines::SOUND_FILE_TYPE;
			resources::soundFile.emplace(fileName, SoundBuffer{});
			if (!resources::soundFile[fileName].loadFromFile(fullFileName)) {
				throwFileError(fileName);
			}
		}
	}

	void loadResources() {
		initDirRoot();
		loadFonts();
		generateHighScoresString();
		loadTextures();
		loadSounds();
	}
}
