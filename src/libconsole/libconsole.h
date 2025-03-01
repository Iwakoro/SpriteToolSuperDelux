#pragma once
#include <cstdarg>
#include <cstddef>
#include <cstdio>
class iohandler;

namespace libconsole {

enum class handle { in, out, err };
bool init();
bool read(char* buffer, int bufsize, handle);
bool write(const char* buffer, int bufsize, handle);
bool write_args(const char* fmt, handle, va_list argptr);
bool write_handle(const char* buffer, int bufsize, FILE* hdl);
bool write_args_handle(const char* fmt, FILE* hdl, va_list list);
size_t bytelen(const char* buffer);
bool isspace(const char ch);

class console {
    friend iohandler;
  protected:
    static int cprintf(const char* fmt, ...);
    static int cfprintf(FILE* stream, const char* fmt, ...);
};

} // namespace libconsole

