<template>
    <div>
        <div class="container">
            <p v-for="(scaffold, key, index) in scaffolds" :key=index>
                <router-link :to="{name: 'scaffolds_show', params: {scaffold_id: scaffold.id}}">{{scaffold.title}}</router-link>
                <router-link :to="{name: 'scaffolds_edits', params: {scaffold_id: scaffold.id}}" >Edit</router-link>
                <router-link to="/scaffolds" v-on:click.native="deletescaffold(scaffold.id)" >Delete</router-link>
            </p>
            <router-link class="btn btn-primary" v-if='user.session' :to="{name: 'scaffolds_new'}" >New Scaffold</router-link>
        </div>
    </div>
</template>

<script>
import axios from 'axios';
import $ from 'jquery';

export default {
    data: function() {
        return {
            scaffolds: [],
        }
    },
    mounted: function() {
        this.getScaffolds();
    },
    methods: {
        getScaffolds: function() {
            this.scaffolds.length = 0;

            axios.get('/api/scaffolds').then((response) => {
                for(var i = 0; i < response.data.length; i++) {
                    this.scaffolds.push(response.data[i]);
                }
            }, (error) => {
                console.log(error);
            })
        },
        deleteScaffold: function(id) {

            axios.delete('/api/scaffolds/' + String(scaffold_id)).then((response) => {
                this.getScaffolds();
                this.$forceUpdate();
            }, (error) => {
                console.log(error);
            })
        }
    }
}
</script>