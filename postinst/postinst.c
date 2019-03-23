#include <CoreFoundation/CoreFoundation.h>
#include <sys/stat.h>
#include <spawn.h>

#define DPKG_PATH "/var/lib/dpkg/info/us.diatr.appsyncunified.list"

#define L_LAUNCHDAEMON_PATH "/Library/LaunchDaemons"
#define SL_LAUNCHDAEMON_PATH "/System" L_LAUNCHDAEMON_PATH

#define INSTALLD_PLIST_PATH_L L_LAUNCHDAEMON_PATH "/com.apple.mobile.installd.plist"
#define INSTALLD_PLIST_PATH_SL SL_LAUNCHDAEMON_PATH "/com.apple.mobile.installd.plist"

#define ASU_INJECT_PLIST_PATH L_LAUNCHDAEMON_PATH "/net.angelxwind.asu_inject.plist"

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
        printf("You seem to have installed AppSync Unified from an APT repository that is not diatrus.github.io/appsync (package ID us.diatr.appsyncunified).\n");
        printf("If someone other than Linus Yang (laokongzi), Karen (angelXwind), or Diatrus is taking credit for the development of this tool, they are likely lying.\n");
        printf("Please only download AppSync Unified from the official repository to ensure file integrity and reliability.\n");
    }
    if (geteuid() != 0) {
        printf("FATAL: This binary must be run as root.\n");
        return 1;
    }
    run_launchctl(INSTALLD_PLIST_PATH_SL, "unload");
    run_launchctl(INSTALLD_PLIST_PATH_SL, "load");
    printf("Current device is an Apple TV, enabling asu_inject...\n");
    chown(ASU_INJECT_PLIST_PATH, 0, 0);
    chmod(ASU_INJECT_PLIST_PATH, 0644);
    run_launchctl(ASU_INJECT_PLIST_PATH, "unload");
    #ifdef POSTINST
        run_launchctl(ASU_INJECT_PLIST_PATH, "load");
    #endif
    return 0;
}
