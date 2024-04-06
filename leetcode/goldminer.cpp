# include <iostream>
# include <string>
# include <fstream>

class Bag {
private:
    static const int MAX_SIZE = 101; 
    char bag[MAX_SIZE] = {};
    int index = 0;
public:
    void push_back(char thing_to_add) {
        if (index < MAX_SIZE) {
            bag[index++] = thing_to_add;
        } else {
            std::cerr << "Bag overflow! Cannot add more elements." << std::endl;
        }
    }
    
    int size() {
        return index;
    }
    
    char get(int pos) const {
        if (pos >= 0 && pos < index) {
            return bag[pos];
        } else {
            std::cerr << "Invalid position!" << std::endl;
            return '\0'; 
        }
    }
    
    int back() {
        if (index > 0) {
            return bag[index - 1];
        } else {
            std::cerr << "No items at back" << std::endl;
            return '\0';
        }
    }
    
    bool empty() const {
        return index == 0;
    }
    
    void pop_back() {
        if (index > 0) {
            --index;
            bag[index] = 0;
        }
    }
};

class Item {
private:
    static const int MAX_SIZE = 100; 
    char item[MAX_SIZE] = {};
    int index = 0;
public:
    void push_back(char thing_to_add) {
        if (index < MAX_SIZE) {
            item[index++] = thing_to_add;
        } else {
            std::cerr << "Item overflow! Cannot add more elements." << std::endl;
        }
    }
    
    char get(int pos) const {
        if (pos >= 0 && pos < index) {
            return item[pos];
        } else {
            std::cerr << "Invalid position!" << std::endl;
            return '\0'; 
        }
    }
    
    bool empty() const {
        return index == 0;
    }
    
    char front() {
        if (index > 0) {
            return item[0];
        } else {
            std::cerr << "No front item" << std::endl;
            return '\0';
        }
    }
    
    void pop_front() {
        if (index > 0) {
            for (int i = 1; i < index; i++) {
                item[i - 1] = item[i];
            }
            --index;
        }
    }
};

class Miner {
private:
    static const int MAX_SIZE = 101;
    int row;
    int col;
    int numRows;
    int numCols;
    char map[MAX_SIZE][MAX_SIZE] = {};
    Item item; 
    Bag bag;    
public:
    Miner(int a, int b) : row(a), col(b), numRows(a), numCols(b) {}
    
    void dig(int col_dig) { 
        if (col_dig < 0 || col_dig >= col) return; 
        bool check_dig = false; 
        for (int i = 0; i < row; i++) { 
            if (map[i][col_dig] == '_' || check_dig == true) continue; 
            else {
                check_dig = true;
                char item_dug = static_cast<char>(map[i][col_dig]);
                map[i][col_dig] = '_'; 
                if (item_dug != '_') { 
                    if (item_dug == 'F' || item_dug == 'M') {
                        item.push_back(item_dug);
                    } else if (item_dug == 'B') {
                        bomb(i, col_dig);
                    } else if (item_dug == 'P') {
                        pig();
                    } else if (item_dug == 'C') {
                        lucky_clover(col_dig);
                    } else { 
                        bag.push_back(item_dug);
                    }
                }
            }
        }
    }
    
    void bomb(int bomb_row, int bomb_col) {
        for (int i = bomb_row - 1; i <= bomb_row + 1; i++) {
            if (i >= row || i < 0) continue;
            for (int j = bomb_col - 1; j <= bomb_col + 1; j++) {
                if (j >= col || j < 0) continue;
                else {
                    map[i][j] = '_';
                }
            }
        }
    }
    
    void pig() {
        bool check_diamond = false;
        int diamond = 'D';
        int gold = 'G';
        while (!bag.empty()) {
            int item_on_top = bag.back();
            if (item_on_top == diamond) {
                return;
            } else if (item_on_top == gold) {
                bag.pop_back();
            }
        }
    }
    
    void insertArray(int insert_row, const char* array) {
        if (row >= 0 && row < MAX_SIZE) {
            row += 1; 
            for (int r = row; r >= insert_row; r--) { 
                for (int c = 0; c < col; c++) {
                    map[r + 1][c] = map[r][c];
                }
            }
            for (int c = 0; c < col; c++) {
                map[insert_row][c] = array[c];
            }
        } else {
            std::cerr << "Invalid row or column index!" << std::endl;
        }
    }
    
    void add_loot(int lucky_row, int add_col, int top_loot) {
        
        int size_add = 0;
        char inserted_row[col];
        for (int i = 0; i < col; i++) {
            if (i >= add_col - 2 && i <= add_col + 2) {
                inserted_row[i] = top_loot;
                size_add++;
            } else inserted_row[i] = '_';
        }
        for (int i = lucky_row; i <= lucky_row + 2; i++) {
            insertArray(i, inserted_row);
        }
    }
    
    void lucky_clover(int lucky_col) {
        int top_loot = 0;
        if (!bag.empty()) {
            top_loot = bag.back();
        } else return;
        int lucky_row = check_row_to_print();
        add_loot(lucky_row, lucky_col, top_loot);
    }
    
    void use() {
        char item_selected;
        if (!item.empty()) {
            item_selected = item.front();
            item.pop_front();
        }
        if (item_selected == 'F') {
            flashlight();
        } else if (item_selected == 'M') {
            magnet();
        }
    }
    
    void magnet() { 
        for (int col_num = 0; col_num < col; col_num++) {
            dig(col_num);
        }
    }
    
    void print_row(int row_selected) {
        std::cout << "MINE LEVEL:" << row - row_selected << std::endl;
        for (int j = 0; j < col; j++) {
            std::cout << map[row_selected][j] << " ";
        }
        std::cout << std::endl;
    }
    
    void flashlight() { 
        for (int i = 0; i < row; i++) {
            int flag = false; 
            for (int j = 0; j < col; j++) {
                if (map[i][j] != '_') { 
                    flag = true;
                }
            }
            if (flag == true) {
                print_row(i); 
                break;
            }
            if (flag == false && i == row - 1) {
                std::cout << "MINE LEVEL:1\n";
                for (int k = 0; k < col; k++) {
                    std::cout << "_ ";
                }
                std::cout << std::endl;
            }
        }
    }
    
    void input() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                char c;
                std::cin >> c;
                map[i][j] = c;
            }
        }
        
    }
    
    int check_row_to_print() {
        int ans = -1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j] != '_') { 
                    ans = i;
                    return ans;
                }
            }
        }
        return ans; 
    }
    
    void print_map() {
        int row_to_print = check_row_to_print();
        if (row_to_print == -1) return;
        for (int i = row_to_print; i < row; i++) {
            for (int j = 0; j < col; j++) {
                std::cout << static_cast<char>(map[i][j]) << " ";
            }
            std::cout << std::endl;
        }
    }
    
    void print_bag() {
        std::cout << "FINAL BAG:" << std::endl;
        int bag_size = bag.size();
        if (bag_size == 0) {
            std::cout << std::endl;
            return;
        }
        for (int i = 0; i < bag_size; i++) {
            std::cout << bag.get(i) << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    
    int col, row, num_operation;
    std::cin >> col >> row >> num_operation;
    Miner miner(row, col);
    miner.input(); 
    for (int i = 0; i < num_operation; i++) {
        std::string s1, s2, s3;
        std::cin >> s1;
        s2 = "DIG";
        s3 = "USE";
        if (s1.compare(s2) == 0) { 
            int num;
            std::cin >> num;
            miner.dig(num); 
        } else if (s1.compare(s3) == 0) {
            miner.use();
        } else continue;
    }
    miner.print_bag();
    std::cout << "FINAL MAP:" << std::endl;
    miner.print_map();
}
