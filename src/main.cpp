/* File Name: main.cpp
 * Author: Kayne Ruse
 * Date (dd/mm/yyyy): 24/04/2013
 * Copyright: (c) Kayne Ruse 2013
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 * Description:
 *     Entry point of the program, and handles fatal errors.
*/
#include "scene_manager.h"

#include <stdexcept>
#include <iostream>

using namespace std;

int main(int, char**) {
	SceneManager app;
	try {
		app.Init();
		app.Proc();
		app.Quit();
	}
	catch(exception& e) {
		cerr << "Fatal error: " << e.what() << endl;
		return 1;
	}
	return 0;
}
