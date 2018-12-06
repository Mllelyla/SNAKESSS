
#include "console"
#include <iostream>
using namespace std;

//int main()
//{
//	//ConsoleContext(size_t w, size_t h, std::string const & t, int16_t fw, int16_t fh, std::wstring const & fn);
//	//hauteur largeur, textes ,hauteur-largeur police, Police
//
//	ConsoleContext context(120,120, "B52", 8,8, L"Consolas");
//
//	//context = ConsoleContext::themeStandard(); un autre theme
//
//	//va assigner le contexte a ce moment la
//	Console::defineContext(context);
//
//
//
//	ConsoleKeyReader & reader{ Console::getInstance().keyReader() };
//	ConsoleWriter & writer{ Console::getInstance().writer() };
//	ConsoleKeyReader::KeyEvents keyEvents;
//
//	reader.installFilter(new ConsoleKeyFilterUp);
//	reader.installFilter(new ConsoleKeyFilterModifiers); //filtre ce que tu veux pas
//
//	//creation image fond background
//
//	writer.createImage("MonImage").fill('*', ConsoleColor::bK + ConsoleColor::tY);
//	writer.push("MonImage");
//
//	ConsoleImage & monImage{ writer.createImage("MonImage") };
//	monImage.drawLine(size_t(30), size_t(60), size_t(35), size_t(60), char(219), ConsoleColor::tc);
//	writer.push("MonImage");
//	//writer.push("TonImage");
//	//return 0;
//	
//	
//	size_t slow{500};
//	while (true) {
//
//
//		for (int i{ 0 }; i < slow; ++i) {
//			for (int j{ 0 }; j < slow; ++j) {
//				for (int k{ 0 }; k < slow; ++k) {
//				}
//			}
//		}
//		
//
//
//		reader.read(keyEvents);  //vecteur de keyEvents
//		for(auto event : keyEvents){
//			if (event.keyV() == 'Q') {
//				cout << "quit" << endl;
//			}
//		}
//
//		if (keyEvents.size() > 0) {
//			cout << keyEvents.front().toDebugString() << endl;  
//			// cout << keyEvents.size();
//		}
//		/*if (keyEvents.size() > 0) {
//
//			//Console::getInstance().writer().randomize();  //ecris qqch de random a l'ecran
//
//		}
//		*/
//		
//
//	}
//	return 0;
//}


