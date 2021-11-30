#include <tugui.hpp>

int tuguiMain() {
    // 阻塞键盘
    TUGUI::Base b;
    wchar_t str[30] = {L" "};
    wchar_t tchar = 'L';
    unsigned int number;
    b.puts(L"input one key, waiting.....\r\n");
    tchar = b.getc();

    b.puts(L"catch the key  the key is \r\n");
    b.putc(tchar);
    b.puts(L"\r\n");
    b.puts(L"now input  9 words   \r\n");

    // 这里10个字符包括 \0 所以是9个字符
    number = b.gets(str, 10);

    b.puts(L"\r\ncatch the key the words are ");
    b.puts(str);

    while (1)
        ;
    return 0;
}