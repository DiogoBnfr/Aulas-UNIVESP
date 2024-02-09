#define true 1
#define false 0
#define ERROR -1
#define MAX 8
#define SN 4

typedef int KEY_TYPE;

typedef int bool;

typedef struct {
	KEY_TYPE data[MAX];
	int bottom[SN + 1];
	int top[SN + 1];
} MULTISTACK;

void init_ms(MULTISTACK* ms) {
	for (int i = 0; i <= SN; i++) {
		ms->bottom[i] = (i * (MAX / SN));
		ms->top[i] = ms->bottom[i] - 1;
	}
}

int size_s(MULTISTACK* ms, int s) {
	if (s < 0 || s >= SN) return ERROR;
	return ms->top[s] - ms->bottom[s] + 1;
}

int size_ms(MULTISTACK* ms) {
	int size = 0;
	for (int i = 0; i < SN; i++) size += size_s(ms, i);
	return size;
}

bool full_size_s(MULTISTACK* ms, int s) {
	if (ms->top[s] == ms->bottom[s + 1] - 1) return true;
	return false;
}

bool pop_s(MULTISTACK* ms, int s, KEY_TYPE* k) {
	if (s < 0 || s >= SN) return false;
	if (ms->top[s] >= ms->bottom[s]) {
		*k = ms->data[ms->top[s]];
		ms->top[s]--;
		return true;
	}
	return false;
}

bool move_s_right(MULTISTACK* ms, int s) {
	if (s < 1 || s > SN - 1) return false;
	if (ms->top[s] < ms->bottom[s + 1] - 1) {
		for (int i = ms->top[s]; i >= ms->bottom[s]; i--) {
			ms->data[i + 1] = ms->data[i];
		}
		ms->top[s]++;
		ms->bottom[s]++;
		return true;
	}
	return false;
}

bool move_s_left(MULTISTACK* ms, int s) {
	if (s < 1 || s >SN - 1) return false;
	if (ms->top[s - 1] < ms->bottom[s] - 1) {
		for (int i = ms->bottom[s]; i <= ms->top[s]; i++) {
			ms->data[i - 1] = ms->data[i];
		}
		ms->top[s]--;
		ms->bottom[s]--;
		return true;
	}
	return false;
}

bool push_s(MULTISTACK* ms, int s, KEY_TYPE k) {
	if (k < 0 || k >= SN) return false;
	if (full_size_s(ms, s)) {
		for (int i = SN - 1; i > s; i--) move_s_right(ms, i);
		if (full_size_s(ms, s)) {
			for (int i = 1; i <= s; i++) move_s_left(ms, i);
			if (full_size_s(ms, s)) return false;
		}
	}
	ms->top[s]++;
	ms->data[ms->top[s]] = k;
	return true;
}

int main(void) { }
