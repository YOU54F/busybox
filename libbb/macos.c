#include <mach-o/dyld.h>
#include <assert.h>

#include "libbb.h"

const char *
macos_get_self_exe_path (void)
{
  static char macos_self_exe_path[PATH_MAX + 1] = { 0 };
  uint32_t macos_self_exe_path_size = sizeof (macos_self_exe_path);

  if (macos_self_exe_path[0] == 0)
    if (_NSGetExecutablePath(macos_self_exe_path,
                             &macos_self_exe_path_size) < 0
        || macos_self_exe_path[0] == 0)
    abort();

  return macos_self_exe_path;
}
