#ifndef UGID_FUNCTIONS
#define UGID_FUNCTIONS

char *userNameFromId(uid_t uid);

uid_t userIdFromName(const char *name);

char *groupNameFromId(gid_t gid);

git_t groupIdFromName(const char *name);

#endif
