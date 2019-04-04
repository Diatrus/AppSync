#include <CoreFoundation/CoreFoundation.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <spawn.h>

#define DPKG_PATH "/var/lib/dpkg/info/us.diatr.appsyncunified.list"

#define L_LAUNCHDAEMON_PATH "/Library/LaunchDaemons"
#define SL_LAUNCHDAEMON_PATH "/System" L_LAUNCHDAEMON_PATH

#define INSTALLD_PLIST_PATH_L L_LAUNCHDAEMON_PATH "/com.apple.mobile.installd.plist"
#define INSTALLD_PLIST_PATH_SL SL_LAUNCHDAEMON_PATH "/com.apple.mobile.installd.plist"

#define CYFRAMEWORK_PATH "/Library/Frameworks/CydiaSubstrate.framework"
#define CYSUB_PATH CYFRAMEWORK_PATH "/CydiaSubstrate"
#define LIBSUB_PATH "/usr/lib/libsubstrate.dylib"

static int run_launchctl(const char *path, const char *cmd) {
    const char *args[] = {"/bin/launchctl", cmd, path, NULL};
    pid_t pid;
    int stat;
    posix_spawn(&pid, args[0], NULL, NULL, (char **) args, NULL);
    waitpid(pid, &stat, 0);
    return stat;
}

int main(int argc, const char **argv) {
    printf("AppSync Unified\n");
    printf("Copyright (C) 2014-2019 Linus Yang, Karen (angelXwind), Diatrus\n");
    printf("** PLEASE DO NOT USE APPSYNC UNIFIED FOR PIRACY **\n");
    if (access(DPKG_PATH, F_OK) == -1) {
        printf("You seem to have installed AppSync Unified from an APT repository that is not diatr.us/appsync (package ID us.diatr.appsyncunified).\n");
        printf("If someone other than Linus Yang (laokongzi), Karen (angelXwind), or Diatrus is taking credit for the development of this tool, they are likely lying.\n");
        printf("Please only download AppSync Unified from the official repository to ensure file integrity and reliability.\n");
    }
    if (geteuid() != 0) {
        printf("FATAL: This binary must be run as root.\n");
        return 1;
    }
    #ifdef POSTINST
        if (access(CYSUB_PATH, F_OK) == -1) {
            if (access(CYFRAMEWORK_PATH, F_OK) == -1) {
                mkdir(CYFRAMEWORK_PATH, 0777);
            }
            symlink(LIBSUB_PATH, CYSUB_PATH);
        }
    #endif
    run_launchctl(INSTALLD_PLIST_PATH_SL, "unload");
    run_launchctl(INSTALLD_PLIST_PATH_SL, "load");
    return 0;
}
