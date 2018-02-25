
    // PoVRay 3.7 Scene File " ... .pov"
// author:  ...
// date:    ...
//--------------------------------------------------------------------------
#version 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"


//This scene was imported from within POVRay
// --------------------------- camera --------------------------------------
#declare Camera_0 = camera {/*ultra_wide_angle*/ angle 75      // front view
                            location  <0.0 , 2.5 ,-8.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.9 , 0.0>}
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 90   // diagonal view
                            location  <2.0 , 2.5 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 90 // right side view
                            location  <3.0 , 1.0 , 0.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_3 = camera {/*ultra_wide_angle*/ angle 90        // top view
                            location  <0.0 , 3.0 ,-0.001>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
camera{Camera_0}
// sun ---------------------------------------------------------------------
light_source{<1500,2500,-2500> color White}
// sky ---------------------------------------------------------------------
plane{<0,1,0>,1 hollow  
       texture{pigment{ bozo turbulence 0.85 scale 1.0 translate<5,0,0>
                        color_map { [0.5 rgb <0.20, 0.20, 1.0>]
                                    [0.6 rgb <1,1,1>]
                                    [1.0 rgb <0.5,0.5,0.5>]}
                       }
               finish {ambient 1 diffuse 0} }      
       scale 10000}
//------------------------------
fog{distance 300000 color White}
// sea ---------------------------------------------------------------------
plane{<0,1,0>, 0 
       texture{Polished_Chrome
               normal { crackle 0.15 scale <0.35,0.25,0.25> turbulence 0.5 } 
               finish { reflection 0.60 }}}

//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------
    
//block
#declare b = box {
    <0,0,0>,
    <4,4,4>
    pigment {Red}
}
  
// sphere for cutting corners
#declare s = sphere {
    <2,2,2>,2.88
    pigment { Red }
}

//cut the corners
#declare base = intersection{

    object {b}
    object {s}
}
   
//number 1
#declare face_1 = sphere {
     <2,4.1,2> 0.4
     pigment{ Yellow }
}

//number 2
#declare face_2 = union {
  sphere {
       <1,1,-0.1> 0.4
       pigment{ Yellow }
  }
  sphere {
       <3,3,-0.1> 0.4
       pigment{ Yellow }
  }
}

//number 3
#declare face_3 = union {
  sphere {
       <4.1,1,1> 0.4
       pigment{ Yellow }
  }
  sphere {
       <4.1,2,2> 0.4
       pigment{ Yellow }
  }
  sphere {
        <4.1,3,3> 0.4
        pigment{ Yellow }
  }
}

//number 4
#declare face_4 = union {
  sphere {
       <-0.1,1,1> 0.4
       pigment{ Yellow }
  }
  sphere {
       <-0.1,1,3> 0.4
       pigment{ Yellow }
  }
  sphere {
        <-.1,3,1> 0.4
        pigment{ Yellow }
  }
  sphere {
       <-0.1,3,3> 0.4
       pigment{ Yellow }
  }
}

//number 5
#declare face_5 = union {
  sphere {
       <1,1,4.1> 0.4
       pigment{ Yellow }
  }
  sphere {
       <1,3,4.1> 0.4
       pigment{ Yellow }
  }
  sphere {
        <2,2,4.1> 0.4
        pigment{ Yellow }
  }
  sphere {
       <3,1,4.1> 0.4
       pigment{ Yellow }
  }
  sphere {
       <3,3,4.1> 0.4
       pigment{ Yellow }
  }
}

//number 6
#declare face_6 = union{
    sphere {
         <1,-0.1,1> 0.4
         pigment{ Yellow }
    }
    sphere {
          <1,-0.1,3> 0.4
          pigment{ Yellow }
    }
    sphere {
         <2,-0.1,1> 0.4
         pigment{ Yellow }
    }
    sphere {
         <2,-0.1,3> 0.4
         pigment{ Yellow }
    }
    sphere {
         <3,-0.1,1> 0.4
         pigment{ Yellow }
    }
    sphere {
         <3,-0.1,3> 0.4
         pigment{ Yellow }
    }
}
          
//indent the sides with their numbers          
#declare dice = difference {
    difference {
        difference {
            difference {
                difference {
                    difference {
                        object { base }
                        object { face_6 }
                    }
                    object { face_5 }
                }
                object { face_4 }
            }
            object { face_3 }
        }
        object { face_2 }
    }
    object { face_1 }
    rotate <-45,0,35> 
}

// orientate and position
object { 
    dice
    rotate <0,clock, 0> 
    translate <0,-.5,0>
}
