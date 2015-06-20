#include <pebble.h>
#include "main.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GBitmap *s_res_stop_icon;
static GBitmap *s_res_lap_icon;
static GFont s_res_roboto_bold_subset_49;
static GFont s_res_roboto_condensed_21;
static GBitmap *s_res_pause_icon;
static BitmapLayer *s_bitmaplayer_1;
static ActionBarLayer *s_actionbar;
static TextLayer *heart_rate;
static TextLayer *exercise_time;
static TextLayer *display_time;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, 0);
  #endif
  
  s_res_stop_icon = gbitmap_create_with_resource(RESOURCE_ID_stop_icon);
  s_res_lap_icon = gbitmap_create_with_resource(RESOURCE_ID_lap_icon);
  s_res_roboto_bold_subset_49 = fonts_get_system_font(FONT_KEY_ROBOTO_BOLD_SUBSET_49);
  s_res_roboto_condensed_21 = fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21);
  s_res_pause_icon = gbitmap_create_with_resource(RESOURCE_ID_pause_icon);
  // s_bitmaplayer_1
  s_bitmaplayer_1 = bitmap_layer_create(GRect(9, 42, 106, 63));
  bitmap_layer_set_background_color(s_bitmaplayer_1, GColorBlack);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_bitmaplayer_1);
  
  // s_actionbar
  s_actionbar = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbar, s_window);
  action_bar_layer_set_background_color(s_actionbar, GColorWhite);
  action_bar_layer_set_icon(s_actionbar, BUTTON_ID_UP, s_res_pause_icon);
  action_bar_layer_set_icon(s_actionbar, BUTTON_ID_SELECT, s_res_stop_icon);
  action_bar_layer_set_icon(s_actionbar, BUTTON_ID_DOWN, s_res_lap_icon);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbar);
  
  // heart_rate
  heart_rate = text_layer_create(GRect(8, 42, 106, 53));
  text_layer_set_background_color(heart_rate, GColorClear);
  text_layer_set_text_color(heart_rate, GColorWhite);
  text_layer_set_text(heart_rate, "199");
  text_layer_set_text_alignment(heart_rate, GTextAlignmentCenter);
  text_layer_set_font(heart_rate, s_res_roboto_bold_subset_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)heart_rate);
  
  // exercise_time
  exercise_time = text_layer_create(GRect(14, 121, 100, 24));
  text_layer_set_background_color(exercise_time, GColorClear);
  text_layer_set_text(exercise_time, "04:04:04");
  text_layer_set_text_alignment(exercise_time, GTextAlignmentCenter);
  text_layer_set_font(exercise_time, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)exercise_time);
  
  // display_time
  display_time = text_layer_create(GRect(15, 8, 100, 28));
  text_layer_set_background_color(display_time, GColorClear);
  text_layer_set_text(display_time, "12:55 AM");
  text_layer_set_text_alignment(display_time, GTextAlignmentCenter);
  text_layer_set_font(display_time, s_res_roboto_condensed_21);
  layer_add_child(window_get_root_layer(s_window), (Layer *)display_time);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(s_bitmaplayer_1);
  action_bar_layer_destroy(s_actionbar);
  text_layer_destroy(heart_rate);
  text_layer_destroy(exercise_time);
  text_layer_destroy(display_time);
  gbitmap_destroy(s_res_stop_icon);
  gbitmap_destroy(s_res_lap_icon);
  gbitmap_destroy(s_res_pause_icon);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_main(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_main(void) {
  window_stack_remove(s_window, true);
}
int main(void) {
	show_main();
	app_event_loop();
	handle_window_unload(s_window);
}
