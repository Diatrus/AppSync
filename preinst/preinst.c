#include <unistd.h>

#define CYSUB_PATH "/Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate"
#define LIBSUB_PATH "/usr/lib/libsubstrate.dylib"

int main(int argc, const char **argv) {
    if (access(CYSUB_PATH, F_OK) == -1) {
        symlink(LIBSUB_PATH, CYSUB_PATH);
    }
}
