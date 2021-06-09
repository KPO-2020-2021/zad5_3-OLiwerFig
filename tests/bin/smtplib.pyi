<?xml version="1.0" ?>
<sdf version="1.5">
  <model name="cabinet">
    <static>true</static>
    <link name="cabinet_bottom_plate">
      <inertial>
        <pose>0 0 -1 0 0 0</pose>
        <inertia>
          <ixx>2.050000</ixx>
          <ixy>0</ixy>
          <ixz>0</ixz>
          <iyy>2.050000</iyy>
          <iyz>0</iyz>
          <izz>2.050000</izz>
        </inertia>
        <mass>25.000000</mass>
      </inertial>
      <collision name="cabinet_bottom_plate_geom">
        <pose>0 0 0.010000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.450000 0.020000</size>
          </box>
        </geometry>
      </collision>
      <visual name="cabinet_bottom_plate_geom_visual">
        <pose>0 0 0.010000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.450000 0.020000</size>
          </box>
        </geometry>
        <material>
          <script>
            <uri>file://media/materials/scripts/gazebo.material</uri>
            <name>Gazebo/Wood</name>
          </script>
        </material>
      </visual>
      <collision name="cabinet_bottom_plate_geom_cabinet_back_plate">
        <pose>0.235000 0 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.020000 0.450000 1.020000</size>
          </box>
        </geometry>
      </collision>
      <visual name="cabinet_bottom_plate_geom_cabinet_back_plate_visual">
        <pose>0.235000 0 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.020000 0.450000 1.020000</size>
          </box>
        </geometry>
        <material>
          <script>
            <uri>file://media/materials/scripts/gazebo.material</uri>
            <name>Gazebo/Wood</name>
          </script>
        </material>
      </visual>
      <collision name="cabinet_bottom_plate_geom_cabinet_left_plate">
        <pose>0 0.235000 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.020000 1.020000</size>
          </box>
        </geometry>
      </collision>
      <visual name="cabinet_bottom_plate_geom_cabinet_left_plate_visual">
        <pose>0 0.235000 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.020000 1.020000</size>
          </box>
        </geometry>
        <material>
          <script>
            <uri>file://media/materials/scripts/gazebo.material</uri>
            <name>Gazebo/Wood</name>
          </script>
        </material>
      </visual>
      <collision name="cabinet_bottom_plate_geom_cabinet_middle_plate">
        <pose>0 0 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.450000 0.020000</size>
          </box>
        </geometry>
      </collision>
      <visual name="cabinet_bottom_plate_geom_cabinet_middle_plate_visual">
        <pose>0 0 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.450000 0.020000</size>
          </box>
        </geometry>
        <material>
          <script>
            <uri>file://media/materials/scripts/gazebo.material</uri>
            <name>Gazebo/Wood</name>
          </script>
        </material>
      </visual>
      <collision name="cabinet_bottom_plate_geom_cabinet_right_plate">
        <pose>0 -0.235000 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.020000 1.020000</size>
          </box>
        </geometry>
      </collision>
      <visual name="cabinet_bottom_plate_geom_cabinet_right_plate_visual">
        <pose>0 -0.235000 0.510000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.020000 1.020000</size>
          </box>
        </geometry>
        <material>
          <script>
            <uri>file://media/materials/scripts/gazebo.material</uri>
            <name>Gazebo/Wood</name>
          </script>
        </material>
      </visual>
      <collision name="cabinet_bottom_plate_geom_cabinet_top_plate">
        <pose>0 0 1.010000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.450000 0.020000</size>
          </box>
        </geometry>
      </collision>
      <visual name="cabinet_bottom_plate_geom_cabinet_top_plate_visual">
        <pose>0 0 1.010000 0 0 0</pose>
        <geometry>
          <box>
            <size>0.450000 0.450000 0.020000</size>
          </box>
        </geometry>
        <material>
          <script>
            <uri>file://media/materials/scripts/gazebo.material</uri>
            <name>Gazebo/Wood</name>
          </script>
        </material>
      </visual>
    </link>
  </model>
</sdf>
