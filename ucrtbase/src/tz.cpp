extern "C" {
    int _daylight;
    int _dstbias;
    long _timezone;
    char* _tzname[] = { (char*)"UTC", (char*)"UTC" };
}

extern "C"
void _tzset() {
    // FIXME - populate _timezone etc.
    // FIXME - copy over _daylight, _timezone, and _tzname to mnposix counterparts
}

extern "C"
long* ____timezone() {
    return &_timezone;
}
