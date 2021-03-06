#include "options.h"
#include <glib.h>
#include "input.h"
#include "output.h"
#include "string_utilities.h"
#include "multus.h"

int main(int argc, char* argv[])
{
    if(parse_options(argc, argv))
        return -1;
    GHashTable* hash = new_wordcount_hash();
    if(!hash)
        say_stream(M_LOG_ERROR, stderr, "Could not allocate table\n");
    char* delimiters = " \n\t\r\"`~!?@#$%^&*()<>»«{}[]_-+=|\\;:,./";
    hash_streams(hash, input_streams(), delimiters);
    input_close();
    output_table(hash);
    g_hash_table_destroy(hash);
    return 0;
}
