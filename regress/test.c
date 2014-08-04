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

void
amp_lt_gt_quote()
{
	char		*result = 0;
		
	htmlescape("& < > \\\"", &result);
	is(result, "&amp; &lt; &gt; &quote;");
	free(result);
}

void
gt_quote_amp_lt_nospace()
{
	char		*result = 0;
		
	htmlescape(">\\\"&<", &result);
	is(result, "&gt;&quote;&amp;&lt;");
	free(result);
}



int
main (int argc, char *argv[])
{

	plan(6);

	amp();
	lt();
	gt();
	quote();
	amp_lt_gt_quote();
	gt_quote_amp_lt_nospace();

	done_testing();
}
