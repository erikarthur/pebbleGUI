#include <pebble.h>
#include "main.h"

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_bebas_18;
static GFont s_res_bebas_49;
static GBitmap *s_res_play_button_white;
static TextLayer *display_time;
static TextLayer *heart_rate;
static TextLayer *exercise_time;
static ActionBarLayer *s_actionbarlayer_1;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, false);
  #endif
  
  s_res_bebas_18 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_bebas_18));
  s_res_bebas_49 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_bebas_49));
  s_res_play_button_white = gbitmap_create_with_resource(RESOURCE_ID_play_button_WHITE);
  // display_time
  display_time = text_layer_create(GRect(23, 8, 100, 24));
  text_layer_set_background_color(display_time, GColorClear);
  text_layer_set_text(display_time, "12:55 AM");
  text_layer_set_text_alignment(display_time, GTextAlignmentCenter);
  text_layer_set_font(display_time, s_res_bebas_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)display_time);
  
  // heart_rate
  heart_rate = text_layer_create(GRect(20, 55, 100, 49));
  text_layer_set_background_color(heart_rate, GColorClear);
  text_layer_set_text(heart_rate, "199");
  text_layer_set_text_alignment(heart_rate, GTextAlignmentCenter);
  text_layer_set_font(heart_rate, s_res_bebas_49);
  layer_add_child(window_get_root_layer(s_window), (Layer *)heart_rate);
  
  // exercise_time
  exercise_time = text_layer_create(GRect(23, 124, 100, 24));
  text_layer_set_background_color(exercise_time, GColorClear);
  text_layer_set_text(exercise_time, "04:04:04");
  text_layer_set_text_alignment(exercise_time, GTextAlignmentCenter);
  text_layer_set_font(exercise_time, s_res_bebas_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)exercise_time);
  
  // s_actionbarlayer_1
  s_actionbarlayer_1 = action_bar_layer_create();
  action_bar_layer_add_to_window(s_actionbarlayer_1, s_window);
  action_bar_layer_set_background_color(s_actionbarlayer_1, GColorWhite);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_UP, s_res_play_button_white);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_SELECT, s_res_play_button_white);
  action_bar_layer_set_icon(s_actionbarlayer_1, BUTTON_ID_DOWN, s_res_play_button_white);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_actionbarlayer_1);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(display_time);
  text_layer_destroy(heart_rate);
  text_layer_destroy(exercise_time);
  action_bar_layer_destroy(s_actionbarlayer_1);
  fonts_unload_custom_font(s_res_bebas_18);
  fonts_unload_custom_font(s_res_bebas_49);
  gbitmap_destroy(s_res_play_button_white);
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
	initialise_ui();
	app_event_loop();
	destroy_ui();
}
