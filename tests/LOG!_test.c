/******************************************************************************
 * Not a logging header test
 *****************************************************************************/

#include "LOG!.h"

LOGH_DEF(ERROR);
LOGH_DEF(TODO);
LOGH_DEF(WARN);
LOGH_DEF(laskflaksfjlasklaskfjklajkjskskalkajljlkfasjljrpqejdcndcocunowendocnaslacalowehnzmalkSfiajfOIJSOPAJakdsnfalksnondaaosivodln);

int main() {
    LOGH_TODO("ouch");
    LOGH_WARN("lame");
    LOGH_laskflaksfjlasklaskfjklajkjskskalkajljlkfasjljrpqejdcndcocunowendocnaslacalowehnzmalkSfiajfOIJSOPAJakdsnfalksnondaaosivodln("very long");
    LOGH_ERROR("bad start");
    return 0;
}
