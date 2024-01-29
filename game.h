void print_game(char* field, unsigned int size, int current_player);

void get_game_input(char* field, unsigned int size, unsigned int* x, unsigned int* y);

void process_game(char* field, unsigned int size, unsigned int x, unsigned int y, int current_player);

int is_game_won(char* field, unsigned int size);
