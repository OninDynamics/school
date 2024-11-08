enum operation {
    command,
    entry,
};

struct Action {
    bool empty;
    operation op;
    double entry;
};

void backtrack() {
    /* Recalculate current program state... */
}

void undo(Action history[], unsigned long histSize) {
    for (int i = 0; i < histSize; i++) {
        if (history[i].empty) {
            history[i-1].empty = true;
            break;
        }
    }
    backtrack();
}






















/*
int main() {

    Action hist[1024];
    double entries[1024];
    unsigned long index = 0;
    string buffer;

    while (true) {
        cout << "> ";
        cin >> buffer;

    return 0;
}
*/
