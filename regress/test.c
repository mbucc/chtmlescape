// Test HTML escaping.
// @since Sun Aug  3 20:16:34 EDT 2014
// @author Mark Bucciarelli <mkbucc@gmail.com>


#include "tap.h"

#include "../htmlescape.h"

void
amp()
{
	char		*result = 0;
		
	htmlescape("&", &result);
	is(result, "&amp;");
	free(result);
}

void
lt()
{
	char		*result = 0;
		
	htmlescape("<", &result);
	is(result, "&lt;");
	free(result);
}

void
gt()
{
	char		*result = 0;
		
	htmlescape(">", &result);
	is(result, "&gt;");
	free(result);
}

void
quote()
{
	char		*result = 0;
		
	htmlescape("\\\"", &result);
	is(result, "&quote;");
	free(result);
}





int
main (int argc, char *argv[])
{

	plan(4);

	amp();
	lt();
	gt();
	quote();

	done_testing();
}
