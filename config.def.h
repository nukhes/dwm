#include <X11/XF86keysym.h>

static const unsigned int borderpx  = 1;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = { "Atkinson Hyperlegible Next Medium:size=10" };
static const char a[]               = "#000000";
static const char b[]               = "#ffb86c";
static const char c[]               = "#ff79c6";
static const char x[]               = "#000000";
static const char *colors[][3]      = { [SchemeNorm] = { c, a, x }, [SchemeSel]  = { b, x, b } };
static const char *tags[]           = { "1", "2", "3", "4", "5" };
static const Rule rules[]           = { { "Gimp", NULL, NULL, 0, 1, -1 }, };
static const float mfact            = 0.55;
static const int nmaster            = 1;
static const int resizehints        = 1;
static const int lockfullscreen     = 1;
static const int refreshrate        = 120;
static const Layout layouts[]       = {{ "", tile }};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SDIR "/home/pedrohenrique/.local/bin/launch.sh"
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
static const char *stcmd[]      = { SDIR, "st", NULL };
static const char *runcmd[]     = { SDIR, "run", NULL };
static const char *rbwcmd[]     = { SDIR, "rbw", NULL };
static const char *srchcmd[]    = { SDIR, "srch", NULL };
static const char *filescmd[]   = { SDIR, "files", NULL };
static const char *browsercmd[] = { SDIR, "browser", NULL };
static const char *scrshotcmd[] = { SDIR, "scrshot", NULL };

static const Key keys[] = {
  { MODKEY,                       XK_p,      spawn,          {.v = runcmd } },
  { MODKEY,                       XK_space,  spawn,          {.v = srchcmd} },
  { MODKEY|ShiftMask,             XK_p,      spawn,          {.v = rbwcmd } },
  { MODKEY|ShiftMask,             XK_s,      spawn,          {.v = scrshotcmd } },
  { MODKEY,                       XK_Return, spawn,          {.v = stcmd } },
  { MODKEY,                       XK_b,      spawn,          {.v = browsercmd } },
  { MODKEY,                       XK_e,      spawn,          {.v = filescmd } },
  { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
  { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY,                       XK_w,      killclient,     {0} },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
  { MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
  { MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
  { MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
  { MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
  { MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
  { MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
  { MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
  { MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
  { MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
  { MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
  { MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  TAGKEYS(                        XK_1,                      0)
  TAGKEYS(                        XK_2,                      1)
  TAGKEYS(                        XK_3,                      2)
  TAGKEYS(                        XK_4,                      3)
  TAGKEYS(                        XK_5,                      4)
  { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  { 0,                            XF86XK_AudioRaiseVolume,  spawn, SHCMD("amixer sset PCM 5%+") },
  { 0,                            XF86XK_AudioLowerVolume,  spawn, SHCMD("amixer sset PCM 5%-") },
  { 0,                            XF86XK_AudioMute,         spawn, SHCMD("amixer sset PCM toggle") },
  { 0,                            XF86XK_MonBrightnessUp,   spawn, SHCMD("brightnessctl set 10%+") },
  { 0,                            XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 10%-") },
};

static const Button buttons[] = {
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
};
