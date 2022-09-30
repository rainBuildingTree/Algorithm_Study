#include <iostream>
#include <vector>
using namespace std;

/*
문제
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 

수빈이가 지금 보고 있는 채널은 100번이다.

입력
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.

출력
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.
*/

int absolute(int input) {
    return (input < 0) ? -input : input;
}

int* check_components(int input) {
    int* components = new int[6];
    for (int i = 0; i < 6; ++i)
        components[i] = -1;
    int index = 0;
    while (input % 10 != input) {
        components[index++] = (input % 10);
        input /= 10;
    }
    components[index] = input;
    return components;
}

int check_length(int input) {
    int length = 1;
    while (input % 10 != input) {
        ++length;
        input /= 10;
    }
    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int target, broken_button_count, required_click, closest_channel_number = 100;
    cin >> target >> broken_button_count;

    bool broken_buttons[10] = {false, false, false, false, false, false, false, false, false, false};


    while (broken_button_count--) {
        int temp;
        cin >> temp;
        broken_buttons[temp] = true;
    }

    for (int i = 0; i < 1000000; ++i) {
        int* components = check_components(i);

        bool is_continue = false;
        for (int j = 0; j < 6; ++j) {
            if (components[j] == -1)
                break;
            if (broken_buttons[components[j]]) {
                is_continue = true;
                break;
            }
        }
        delete components;
        if (is_continue)
            continue;

        closest_channel_number = (absolute(target - closest_channel_number) > absolute(target - i)) ? i : closest_channel_number;
    }

    required_click = check_length(closest_channel_number) + absolute(target-closest_channel_number);
    required_click = (required_click > absolute(target - 100)) ? absolute(target - 100) : required_click;
    cout << required_click << '\n';

    return 0;
}