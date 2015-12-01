#include <iostream>
#include <string>

std::string remove_repeats(std::string s) {
    bool map[26] = {0};
    std::string ret = "";
    for (char c : s) {
        if (!map[c - 'a'])
            ret += c;
        map[c - 'a'] = true;
    }

    return ret;
}

void hangman_judge(std::string word, std::string guesses) {
    bool occurences[26] = {0};

    for (char c : word)
        occurences[c - 'a'] = true;

    unsigned correct = 0;
    unsigned wrong = 0;
    word = remove_repeats(word);
    guesses = remove_repeats(guesses);

    for (char c : guesses) {
        if (occurences[c - 'a'])
            ++correct;
        else
            ++wrong;

        if (correct >= word.size() || wrong >= 7)
            break;
    }

    if (correct >= word.size() && wrong < 7)
        std::cout << "You win." << std::endl;
    else if (wrong >= 7)
        std::cout << "You lose." << std::endl;
    else
        std::cout << "You chickened out." << std::endl;
}

int main() {
    std::string word;
    std::string guess;
    int n;
    while (std::cin >> n) {
        if (n < 0)
            break;

        std::cin >> word;
        std::cin >> guess;

        std::cout << "Round " << n << std::endl;
        hangman_judge(word, guess);
    }
    return 0;
}
