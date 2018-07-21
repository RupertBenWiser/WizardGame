#pragma once

struct KeyEvent {
	int action;
	int key;

	KeyEvent(int a, int k) : action(a), key(k) {}
};